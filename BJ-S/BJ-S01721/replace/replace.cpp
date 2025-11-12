#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
struct sp{
	string s1,s2;
}sn[maxn];

string sq1,sq2;

struct px{
	int z;
	int pi;
}a[200005];

bool cmp(px qa,px qb){
	return qa.z<qb.z;
}
int ans=0;
int mbq;
int fs[200005];
int zs[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sn[i].s1>>sn[i].s2;
		a[i].z=sn[i].s1.find("b")-sn[i].s2.find("b");
		a[i].pi=i;
		//cout<<a[i].pi<<" "<<a[i].z<<endl;
	}

	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].z==a[i-1].z&&i!=1)continue;
		if(a[i].z<0){
			fs[-a[i].z]=i;
		}
		else zs[a[i].z]=i;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>sq1>>sq2;
		mbq=sq1.find("b")-sq2.find("b");
		int qt;
		if(mbq<0){
			qt=fs[-mbq];
		}
		else{
			qt=zs[mbq];
		}
		for(int j=qt;;j++){
			if(a[j].z!=mbq) break;
			int y=sq1.find(sn[a[j].pi].s1);
			//cout<<y<<" "<<a[j].pi<<endl;
			if(y!=-1)
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
