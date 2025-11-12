#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int main(){
	//期望作对1~5和13数据点得30 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans=0;
	if(k==0){
		int cnt;//记录有没有连续的1，因为连续的偶数个1异或起来等于0 
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(cnt>=2){//一定能通过减一或不减得到偶数 
					ans++;//多了一个0 
				}
				cnt=0;//cnt归零 
				ans++;//本来就有一个0
			}else{
				cnt++;//记录有连续的1 
			}
		}
	}else{//是1 
		for(int i=1;i<=n;i++){
			if(a[i]==k){//本来就有一个1
				ans++;
			}//零不管怎么异或都为零 
		}
	}
	cout << ans;
	return 0;
}