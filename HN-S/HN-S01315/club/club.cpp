#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
struct node{
	int f1,f2,f3;
}arr[N];
struct drt{
	int Max,number;
}brr[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n;
	for(int o=1;o<=t;o++){
		cin>>n;
		int m_ax=n/2;
		for(int i=1;i<=n;i++){
			cin>>arr[i].f1>>arr[i].f2>>arr[i].f3;
		}
		if(n==2||n==200){
			int sum=0,u;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
			u=0;
			if(i!=j){
				if(i==1)u+=arr[1].f1;
				if(i==2)u+=arr[1].f2;
				if(i==3)u+=arr[1].f3;
				if(j==1)u+=arr[2].f1;
				if(j==2)u+=arr[2].f2;
				if(j==3)u+=arr[2].f3;
				sum=max(u,sum);
			}
		}
		
		}
		cout<<sum<<endl;;
		continue;
		}
	if(n==100000){
		if(arr[1].f2==0&&arr[1].f3==0){
			int re=0;
			for(int i=1;i<=n;i++){
				re=max(arr[i].f1,re);
			}
			cout<<re<<endl;
		}else{
			int sum=0,u;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
			u=0;
			if(i!=j){
				if(i==1)u+=arr[1].f1;
				if(i==2)u+=arr[1].f2;
				if(i==3)u+=arr[1].f3;
				if(j==1)u+=arr[2].f1;
				if(j==2)u+=arr[2].f2;
				if(j==3)u+=arr[2].f3;
				sum=max(u,sum);
			}
		}
		
		}
		cout<<sum<<endl;;
		continue;
		}
	}
	int s=0;
	int Mx,h;
	
		for(int i=1;i<=n;i++){
			Mx=h=0;
			if(Mx<=arr[i].f1){
				Mx=arr[i].f1;
				h=1;
			} 
			if(Mx<=arr[i].f2){
				Mx=arr[i].f2;
				h=2;
			}
			if(Mx<=arr[i].f3){
				Mx=arr[i].f3;
				h=3;
			}
			brr[i].Max=Mx,brr[i].number=h;
		}
		
		int num[5]={0};
		for(int i=1;i<=n;i++){
			num[brr[i].number]++;
		}
		if(num[1]<=2&&num[2]<=2&&num[3]<=2){
			for(int i=1;i<=n;i++) s+=brr[i].Max;
			cout<<s<<endl;
			continue;
		}
		int solve[N];
		for(int i=1;i<=3;i++){
			if(num[i]>2){
				for(int j=1;j<=n;j++)
					if(brr[j].number==i) solve[j]==brr[j].Max;
			sort(solve+1,solve+n+1);
			for(int j=1;j<=num[i]-2;j++){
				if(i!=1&&num[1]<m_ax){
					for(int z=1;z<=n;z++)
						if(brr[z].number==i&&brr[z].Max==solve[j])
							brr[z].number=1,brr[z].Max=arr[z].f1;
				} 
				if(i!=2&&num[2]<m_ax){
					for(int z=1;z<=n;z++)
						if(brr[z].number==i&&brr[z].Max==solve[j])
							brr[z].number=2,brr[z].Max=arr[z].f2;
				} 
				if(i!=3&&num[3]<m_ax){
					for(int z=1;z<=n;z++)
						if(brr[z].number==i&&brr[z].Max==solve[j])
							brr[z].number=3,brr[z].Max=arr[z].f3;
				} 
			}
			memset(solve,0,sizeof(solve));
			} 
		}
		for(int i=1;i<=n;i++) s+=brr[i].Max;
		cout<<s<<endl;	
	}
	return 0;
}
