#include<bits/stdc++.h>
using namespace std;
int n,m,shabixiaor,n_xiaor,m_xiaor;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int bababoyi[n*m]={};
	for(int i=0;i<n*m;i++)cin>>bababoyi[i];
	shabixiaor=bababoyi[0];
	sort(bababoyi,bababoyi+n*m,greater<int>());
	for(int i=0;i<m*n;i++){
		if(bababoyi[i]==shabixiaor){
			int num=i+1,num2=num,cnt=0;
			while(num2>0){
				if(double(double(num2)/n)>1){
					num2-=n;
					cnt++;
				}
				else break;
			}
			m_xiaor=cnt+1;
			if (m_xiaor % 2 != 0)n_xiaor=num2;
			else if (m_xiaor % 2 == 0)n_xiaor=n-num2+1;
			break;
		}
	}
	cout<<m_xiaor<<" "<<n_xiaor;
	return 0;
}
