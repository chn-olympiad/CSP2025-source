#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct tab{
	int a,b,c;
}num[100005];
bool cmp(tab i,tab j){
	if(i.a==j.a&&i.b==j.b)
		return i.c>j.c;
	else if(i.a==j.a)
		return i.b>j.b;
	return i.a>j.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>num[j].a>>num[j].b>>num[j].c;
		sort(num+1,num+1+n,cmp);
		if(n==2)
			cout<<max(num[1].a+num[2].b,max(num[2].a+num[1].b,max(num[1].a+num[2].c,max(num[2].a+num[1].c,max(num[1].b+num[2].c,num[2].b+num[1].c)))))<<endl;
		else{
			int ans=0;
			for(int j=1;j<=n/2;j++)
				ans+=num[j].a;
			cout<<ans<<endl;
		}
	}
	return 0;
}

