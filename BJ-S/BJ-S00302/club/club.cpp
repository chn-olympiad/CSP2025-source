#include <bits/stdc++.h>
#define int long long
//#define foradd(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
//#define forsub(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
struct stu{
	int num1,num2,num3,bestnum,maxsub,maxsubpoint,ending,maxsubpoint2,maxsubpoint3;
};
int cmp(stu a,stu b){
	return a.maxsub>b.maxsub;
}
stu a[100005];
int t,n,l,numa=0,numb=0,numc=0;
signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		memset(a,0,sizeof(a));
		cin >> n;
		l=n/2;
		for(int i=(1);(i)<=(n);(i)++){
			//输入开始
			cin >> a[i].num1 >> a[i].num2 >> a[i].num3;
			a[i].bestnum=max(a[i].num1,max(a[i].num2,a[i].num3));
			//int max12=abs(a[i].num1-a[i].num2);
			//int max23=abs(a[i].num2-a[i].num3);
			//int max13=abs(a[i].num1-a[i].num3);
			int maxer;
			if (a[i].bestnum==a[i].num1){
				maxer=max(a[i].num2,a[i].num3);
			}
			else if (a[i].bestnum==a[i].num2){
				maxer=max(a[i].num1,a[i].num3);
			}
			else if (a[i].bestnum==a[i].num3){
				maxer=max(a[i].num1,a[i].num2);
			}
			a[i].maxsub=a[i].bestnum-maxer;
			if (max(a[i].num1,max(a[i].num2,a[i].num3))==a[i].num1){
				a[i].maxsubpoint=1;
				if (max(a[i].num2,a[i].num3)==a[i].num2){
					a[i].maxsubpoint2=2;
					a[i].maxsubpoint3=3;
				}else{
					a[i].maxsubpoint2=3;
					a[i].maxsubpoint3=2;
				}
			}
			else if (max(a[i].num1,max(a[i].num2,a[i].num3))==a[i].num2){
				a[i].maxsubpoint=2;
				if (max(a[i].num1,a[i].num3)==a[i].num3){
					a[i].maxsubpoint2=1;
					a[i].maxsubpoint3=3;
				}else{
					a[i].maxsubpoint2=3;
					a[i].maxsubpoint3=1;
				}
			}
			else if (max(a[i].num1,max(a[i].num2,a[i].num3))==a[i].num3){
				a[i].maxsubpoint=3;
				if (max(a[i].num2,a[i].num1)==a[i].num1){
					a[i].maxsubpoint2=1;
					a[i].maxsubpoint3=2;
				}else{
					a[i].maxsubpoint2=2;
					a[i].maxsubpoint3=1;
				}
			}
			//cout << a[i].num1 << ' ' << a[i].num2 << ' ' << a[i].num3 << ' ' << a[i].maxsubpoint << ' ' << a[i].maxsub << '\n';
			//输入完成
			//sort(a+1,a+n+1,cmp);
		}
		l=n/2;
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++){
			//cout << a[i].maxsub << ' ';
		}
		//cout << '\n';
		numa=0,numb=0,numc=0;
		for(int i=(1);(i)<=(n);(i)++){//让差距最大的先上
			if (a[i].maxsubpoint==1&&numa<l){
				numa++;
				a[i].ending=1;
			}	
			else if (a[i].maxsubpoint==2&&numb<l){
				numb++;
				a[i].ending=2;
				//cout << "yes";
			}
			else if (a[i].maxsubpoint==3&&(numc<n/2)){
				++numc;
				a[i].ending=3;
				//cout << "y" << numc << ' ' << (numc<=n/2);
			}
			else{
				//cout << "yes";
				//cout << a[i].maxsubpoint2;
				if (a[i].maxsubpoint2==1&&numa<l){
					numa++;
					a[i].ending=1;
				}
				else if (a[i].maxsubpoint2==2&&numb<l){
					numb++;
					a[i].ending=2;
				}
				else if (a[i].maxsubpoint2==3&&numc<l){
					numc++;
					a[i].ending=3;
					//cout << "y" ;
				}
				else {
					if (a[i].maxsubpoint3==1&&numa<l){
						numa++;
						a[i].ending=1;
					}
					else if (a[i].maxsubpoint3==2&&numb<l){
						numb++;
						a[i].ending=2;
					}
					else if (a[i].maxsubpoint3==3&&numc<l){
						numc++;
						a[i].ending=3;
					}
				}			
			}
		}
		int ans=0;
		for(int i=(1);(i)<=(n);(i)++){
			if (a[i].ending==1){
				ans+=a[i].num1;
			}
			else if (a[i].ending==2){
				ans+=a[i].num2;
			}
			else if (a[i].ending==3){
				ans+=a[i].num3;
			}
			//cout << a[i].ending << ' ';
		}
		//cout << '\n';
		cout << ans << '\n';
		ans=0;
	}
	return 0;
}

