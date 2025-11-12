#include<bits/stdc++.h>
using namespace std;
int t,n;
struct worker{
	int a,b,c,maxn;
}a[100001];
int f(int a,int b,int c){
	if (a>=b && a>=c) return 1;
	if (b>=a && b>=c) return 2;
	if (c>=a && c>=b) return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		int s1=0,s2=0,s3=0,num1=0,num2=0,num3=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxn=f(a[i].a,a[i].b,a[i].c);
			if (a[i].maxn==1 && s1+1<=n/2) s1++,num1+=a[i].a;
			else if (a[i].maxn==2 && s2+1<=n/2) s2++,num2+=a[i].b;
			else if (a[i].maxn==3 && s3+1<=n/2) s3++,num3+=a[i].c;
		}
		cout<<num1+num2+num3<<endl;
	}
	return 0;
}
