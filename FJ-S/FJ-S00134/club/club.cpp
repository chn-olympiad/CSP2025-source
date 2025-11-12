#include<bits/stdc++.h>
using namespace std;
int t,n;
struct hgd{
	int a1,a2,a3;
	int aa1,aa2,aa3;
	int id1=1,id2=2,id3=3;
}a[100005];
bool cmp(hgd x,hgd y){
	if(x.aa1==y.aa1){
		if(x.aa2==y.aa2){
			return x.aa3>y.aa3;
		}else{
			return x.aa2>y.aa2;
		}
	}else{
		return x.aa1>y.aa1;
	}
}
void swp(int j){
	if(a[j].aa1<a[j].aa2){
		swap(a[j].aa1,a[j].aa2);
		swap(a[j].id1,a[j].id2);	
	}
	if(a[j].aa1<a[j].aa3){
		swap(a[j].aa1,a[j].aa3);
		swap(a[j].id1,a[j].id3);
	}
	
	if(a[j].aa2<a[j].aa3){
		swap(a[j].aa2,a[j].aa3);
		swap(a[j].id2,a[j].id3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int p[4]={0,n/2,n/2,n/2},cnt=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			a[j].aa1=a[j].a1;
			a[j].aa2=a[j].a2;
			a[j].aa3=a[j].a3;
			swp(j);
		}
		sort(a+1,a+1+n,cmp);
		for(int j=1;j<=n;j++){
			if(p[a[j].id1]>0){
				p[a[j].id1]--;
				cnt+=a[j].aa1;
			}else{
				p[a[j].id2]--;
				cnt+=a[j].aa2;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
