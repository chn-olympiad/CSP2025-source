#include<bits/stdc++.h>
using namespace std;
int n;
struct nn{
	int a1,a2,a3;
};
bool cmp(nn p,nn q){
	if(p.a1>q.a1)return 1;
	else if(p.a1==q.a1&&p.a2>q.a2)return 1;
	else if(p.a1==q.a1&&p.a2==q.a2&&p.a3>q.a3)return 1;
	return 0;
}
nn a[100005];
void t1(){
	int ans=0;
	for(int i=1;i<=n/2;i++){ { ans+=a[i].a1; } };
	cout<<ans<<endl;
}
void t2(){
	int ans=0,f1=0,f2=0;
	for(int i=1;i<=n;i++){
		if(a[i].a1>a[i].a2){
			if(f1<=n/2){ ans+=a[i].a1;f1++; }
			else { ans+=a[i].a2;f2++; }
		}else{
			{ ans+=a[i].a2;f2++; }
		}
	}
	cout<<ans<<endl;
}
void t3(){
	int ans=0,f1=0,f2=0,f3=0;
	for(int i=1;i<=n;i++){
		if((a[i].a1>a[i].a2&&a[i].a1>a[i].a3)){
			if(f1<=n/2){
				ans+=a[i].a1;
				f1++;
				printf("D1\n");
			}else{
				if(a[i].a2>a[i].a3&&f2<=n/2){
					ans+=a[i].a2;
					f2++;
					printf("D2\n");
				}
				else{
					ans+=a[i].a3;
					f3++;
					printf("D3\n");
				}
			}
		}
		if((a[i].a2>a[i].a1&&a[i].a2>a[i].a3)){
			if(f2<=n/2){
				ans+=a[i].a2;
				f2++;
				//printf("D2\n");
			}else{
				if(a[i].a1>a[i].a3&&f1<=n/2){
					ans+=a[i].a1;
					f1++;
					//printf("D1\n");
				}
				else{
					ans+=a[i].a3;f3++;
					//printf("D3\n");
				}
			}
		}
		if((a[i].a3>a[i].a1&&a[i].a3>a[i].a2)){
			if(f3<=n/2){
				ans+=a[i].a3;
				f3++;
				//printf("D3\n");
			}else{
				if(a[i].a2>a[i].a1&&f2<=n/2){
					ans+=a[i].a2;f2++;
					//printf("D2\n");
				}
				else{
					ans+=a[i].a1;f1++;
					//printf("D1\n");
				};
			}
		}
	}
	cout<<ans<<endl;
}
void task(){
	scanf("%d",&n);
	bool flag2=1,flag3=1;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
		if(a[i].a2)flag2=0;
		if(a[i].a3)flag3=0;
	}
	sort(a+1,a+n+1,cmp);
	if(flag2){
		if(flag3)t1();
		else t2();
	}else t3();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		task();
		//cout<<"-----------------"<<endl;
	}
	fclose(stdin);fclose(stdout);
}
