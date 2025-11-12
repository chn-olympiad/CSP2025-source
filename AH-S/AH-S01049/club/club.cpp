#include<bits/stdc++.h>
#define N 100010
using namespace std;
int t,n,num[5],ans;
struct MYD{
	int id,a;
};
bool cmp1(MYD a,MYD b){
	return a.a>b.a;
}
struct Studt{
	MYD myd[5];
	int vim,id;
	void Sort(){
		sort(myd+1,myd+4,cmp1);
	}
	int deta(){
		return myd[vim+1].a-myd[vim].a;
	}
	int nto(){
		return myd[vim].id;
	}
}a[N];
bool cmp2(Studt a,Studt b){
	return a.deta()>b.deta();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++){
			num[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i].id=i;
			for(int j=1;j<=3;j++){
				cin>>a[i].myd[j].a;
				a[i].myd[j].id=j;
			}
			a[i].Sort();
			a[i].vim=0;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].deta();
			a[i].vim=1;
			num[a[i].nto()]++;
		}
		for(int i=1;i<=2;i++){
			sort(a+1,a+n+1,cmp2);
			for(int j=1;j<=n;j++){
				if(num[a[j].nto()]>n/2){
					num[a[j].nto()]--;
					ans+=a[j].deta();
					a[j].vim++;
					num[a[j].nto()]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
