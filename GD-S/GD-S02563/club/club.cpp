#include<bits/stdc++.h>
using namespace std;
struct person{
	int club1;
	int club2;
	int club3;
	int amax;
	bool visiting=0;
};
person a[100005];
bool cmp1(person x,person y){
	return x.club1>y.club1; 
}
bool cmp2(person x,person y){
	return x.club2>y.club2;
}
bool cmp3(person x,person y){
	return x.club3>y.club3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int times=0;
	int n;
	int maxp;
	int visited[100005]={};//用于记录第i个人是否已经被分配 
	for(int k=0;k<t;k++){
		cin>>n;
		maxp=n/2;
//		cout<<maxp<<endl;
		for(int i=1;i<=n;i++){
			cin>>a[i].club1>>a[i].club2>>a[i].club3;
			a[i].visiting=0;
			a[i].amax=max(max(max(a[i].club1,a[i].club2),max(a[i].club3,a[i].club2)),max(a[i].club1,a[i].club3));
//			cout<<amax[i]<<' ';
		}
//		cout<<endl;
//		cout<<amax[4];
		//先选择第一个部门
		sort(a+1,a+n+1,cmp1);
		times=0;
		int sum1=0;
		for(int i=1;i<=n && times<=maxp;i++){
//			cout<<a[i].club1<<a[i].club2<<a[i].club3<<endl;
//			cout<<a[i].club1;
			if(a[i].club1==a[i].amax){
				sum1+=a[i].club1;
				a[i].visiting=1;
				times++;
//				cout<<sum1<<endl;
			}
		} 
//		cout<<sum1<<endl; 
		//在选择第二个部门
		sort(a+1,a+1+n,cmp2);
		times=0;
		int sum2=0;
		for(int i=n;i>=1 && times<=maxp;i--){
//			cout<<a[i].club1<<a[i].club2<<a[i].club3<<endl;
			if(a[i].club2==a[i].amax && a[i].visiting!=1){
				sum2+=a[i].club2;
				a[i].visiting=1;
				times++;
			}
		}
		//最后选择第三个部门
		sort(a+1,a+1+n,cmp3);
		times=0;
		int sum3=0;
		for(int i=n;i>=1 && times<=maxp;i--){
//			cout<<a[i].club1<<a[i].club2<<a[i].club3<<endl;
			if(a[i].club3==a[i].amax && a[i].visiting!=1){
				sum3+=a[i].club3;
				a[i].visiting=1;
				times++;
			}
		}
		cout<<sum1+sum2+sum3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
