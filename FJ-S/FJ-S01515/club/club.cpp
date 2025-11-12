#include<bits/stdc++.h>
using namespace std;
int T;
int n;
long long qread(){
	char ch=getchar();
	long long ret=0;
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
struct node{
	long long a1,a2,a3,a4;
}a[100050];
bool cmp(node x,node y){
	return x.a4<y.a4;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].a1=qread();a[i].a2=qread();a[i].a3=qread();
			a[i].a4=max(a[i].a1,max(a[i].a2,a[i].a3))*2+min(a[i].a1,min(a[i].a2,a[i].a3))-a[i].a1-a[i].a2-a[i].a3;
//			cout<<a[i].a4<<endl;
		}
		long long tot1=0,tot2=0,tot3=0;
		long long ans=0;
		long long a1,a2,a3,a4;
		for(int i=1;i<=n;i++){
			a1=a[i].a1,a2=a[i].a2,a3=a[i].a3,a4=a[i].a4;
			if(a1==a2&&a2==a3){
				ans+=a1;
				tot1++;
				continue;
			}
			if(a1>=a2&&a1>=a3){
				ans+=a1;
				tot1++;
			}else if(a2>=a1&&a2>=a3){
				ans+=a2;
				tot2++;
			}else if(a3>=a1&&a3>=a2){
				ans+=a3;
				tot3++;
			}
		}
		long long tot=max(tot1,max(tot2,tot3));
//		cout<<tot<<endl;
		if(tot>n/2){
			sort(a+1,a+n+1,cmp);
			for(int i=1,j=1;i<=n&&j<=tot-n/2;i++){
				a1=a[i].a1,a2=a[i].a2,a3=a[i].a3,a4=a[i].a4;
				if(tot1>=n/2&&((a1>=a2&&a1>=a3)||(a1==a2&&a2==a3))){
					ans-=a4;
					j++;
//					cout<<1<<' '<<a4<<endl;
				}else if(tot2>=n/2&&a2>=a1&&a2>=a3&&(a1!=a2||a1!=a3)){
					ans-=a4;
					j++;
//					cout<<2<<' '<<a4<<endl;
				}else if(tot3>=n/2&&a3>=a1&&a3>=a2&&(a1!=a2|a1!=a3)){
					ans-=a4;
					j++;
//					cout<<3<<' '<<a4<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
