#include<bits/stdc++.h>
using namespace std;
int t,n,as,bs,cs,ans;
struct stu{
	int a,b,c,num;
}a[100005];
bool cmp(stu a,stu b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
bool aaa(stu a,stu b){
	return min(a.a-a.b,a.a-a.c)<min(b.a-b.b,b.a-b.c);
}
bool bbb(stu a,stu b){
	return min(a.b-a.c,a.b-a.a)<min(b.b-b.c,b.b-b.a);
}
bool ccc(stu a,stu b){
	return min(a.c-a.a,a.c-a.b)<min(b.c-b.a,b.c-b.b);
}
int chk(int a,int b,int c){
	if(a>=b&&a>=c)return 1;
	if(b>=a&&b>=c)return 2;
	return 3;
}
void turna(){
	sort(a+1,a+n+1,aaa);
	for(int i=1;i<=n;i++){
		if(a[i].num!=1)continue;
		as--;
		if(a[i].b>a[i].c)ans-=a[i].a-a[i].b;
		else ans-=a[i].a-a[i].c;
		if(as<=n/2)return ;
	}
}
void turnb(){
	sort(a+1,a+n+1,bbb);
	for(int i=1;i<=n;i++){
		if(a[i].num!=2)continue;
		bs--;
		if(a[i].a>a[i].c)ans-=a[i].b-a[i].a;
		else ans-=a[i].b-a[i].c;
		if(bs<=n/2)return ;
	}
}
void turnc(){
	sort(a+1,a+n+1,ccc);
	for(int i=1;i<=n;i++){
		if(a[i].num!=3)continue;
		cs--;
		if(a[i].a>a[i].b)ans-=a[i].c-a[i].a;
		else ans-=a[i].c-a[i].b;
		if(cs<=n/2)return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		as=bs=cs=ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int p=chk(a[i].a,a[i].b,a[i].c);
			if(p==1){
				a[i].num=1;
				ans+=a[i].a;as++;
			}
			else if(p==2){
				a[i].num=2;
				ans+=a[i].b;bs++;
			}
			else if(p==3){
				a[i].num=3;
				ans+=a[i].c;cs++;
			}
		}
		if(as<=n/2&&bs<=n/2&&cs<=n/2)cout<<ans<<endl;
		else {
			if(as>n/2)turna();
			else if(bs>n/2)turnb();
			else turnc();
			cout<<ans<<endl;
		} 
	}
	return 0;
} 
