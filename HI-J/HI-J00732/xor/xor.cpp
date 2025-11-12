#include<bits/stdc++.h>
#include<map>
using namespace std;
struct dev{
	long long a=0,b=0;
};
bool cmp(dev x,dev y){
	if(x.b==y.b){
		return x.a<y.a;
	}
	return x.b<y.b;
}
bool l[100003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,z,c,u=0;
	vector<long long>a;
	dev b[100003];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>c;
		a.push_back(c);
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++){
			z=0;
			for(long long x=i;x<=j;x++)
				z=(z xor a[x]);
			if(z==m){
				u++;
				b[u].a=i;
				b[u].b=j-i;
			}
		}
}
	sort(b+1,b+u+1,cmp);
	bool h;
	int s=0;
	for(int i=1;i<=u;i++){
		h=0;
		for(int j=b[i].a;j<=b[i].a+b[i].b;j++){
			if(l[j]==1){
				h=1;
				break;
			}
		}
		if(h==0){
			for(int j=b[i].a;j<=b[i].a+b[i].b;j++){
				l[j]=1;
			}
			s++;
		}
	}
	cout<<s;
	
	return 0;
	
}

