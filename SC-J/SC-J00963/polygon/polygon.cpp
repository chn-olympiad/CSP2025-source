#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;

long long a[N],n,k,cnt,ans;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int flag = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n >= 3){
		for(int i = 3;i <= n;i++){
//			cout<<flag;
			flag = 0;
			for(int j = 1;j <= i;j++){
				cnt += a[j];
			}
//			cout<<"cnt:"<<cnt<<"\n";
//			cout<<"a[j]:";
			for(int j = 1;j <= i;j++){
				if(cnt <= a[j]*2){
					flag = 1;
//					cout<<"666"<<"-->";
				}
//				cout<<a[j]*2<<' ';
			}
//			cout<<"\n"<<"flag:"<<flag<<"\n";
			if(flag == 0){
				ans += 1;
			}else{
				flag == 0;
			}
//			cout<<"flag == 0"<<"\n\n";
			flag == 0;
			cnt = 0;
		}
	}else{
//		cout<<"不对"; 
		cout<<0;
	}
//	cout<<"\n";
	cout<<ans;

}