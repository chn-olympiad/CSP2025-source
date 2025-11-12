#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
struct stu{
	int a,b,c;
};
stu s[MAXN];
long long ans;
long long sum;
int x,y,z;
int l[10],r[10];
int q,w,e;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		 q+=s[i].a;
		 w+=s[i].b;
		 e+=s[i].c;
		 }
		for(int i=1;i<=n;i++){
			if(n>2){
	      ans += max(s[i].a,max(s[i].b,s[i].c));
	      if(s[i].a==0||s[i].b==0||s[i].c==0){
	      	ans=max(q,max(w,e));
		  }
	}
	if(n==2){
	  l[1]=s[i].a;
	  l[2]=s[i].b;
	  l[3]=s[i].c;
	  r[1]=s[i+1].a;
	  r[1]=s[i+1].b;
	  r[1]=s[i+1].c;
	  sort(l,l+n+1,cmp);
	  sort(r,r+n+1,cmp);
	  if(r[1]-r[2]>l[1]-l[2]) ans+=r[1]+l[2];
	  else ans+=r[2]+l[1];
}
}
cout<<ans;
ans =0;
}
return 0;
}