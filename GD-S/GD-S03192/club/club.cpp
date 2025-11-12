#include <bits/stdc++.h>
using namespace std;
int T,n,f[100005][3],a,b,c,p1[100005],p2[100005],p3[100005],l1=0,l2=0,l3=0;
long long ans=0;
bool cmp(int a,int b){
	return a>b;
}
int man(){
	ans=0;
	l1=l2=l3=0;
	//cin>>n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//cin>>a>>b>>c;
		scanf("%d%d%d",&a,&b,&c);
		f[i][0]=a,f[i][1]=b,f[i][2]=c;
		if(a>=b&&a>=c){
			p1[l1++]=a-max(b,c);
			ans+=a;
		}else if(b>=a&&b>=c){
			p2[l2++]=b-max(a,c);
			ans+=b;
		}else{
			p3[l3++]=c-max(a,b);
			ans+=c;
		}
	}
	if(l1>n/2){
		sort(p1,p1+l1,cmp);
		while(l1>n/2){
			ans-=p1[--l1];
		}
	}else if(l2>n/2){
		sort(p2,p2+l2,cmp);
		while(l2>n/2){
			ans-=p2[--l2];
		}
	}else if(l3>n/2){
		sort(p3,p3+l3,cmp);
		while(l3>n/2){
			ans-=p3[--l3];
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		man();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
