#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int sum = 0;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> isPrime(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1 && k!=a[0]){
		cout<<0;
		return 0;
	}else if(n==1 && k==a[0]){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			isPrime[i] = 1;
			sum++;
		}
	}
	if(sum==n){
		cout<<sum;
		return 0;
	} 
	int l = -1;
	int r = -1;
	int flag1=0,flag2=0,flag3=0,cnt=2;
	for(int i=0;i<n;i++){
		if(isPrime[i]==0 && flag1==0){
			l = i;
			flag1=1;
		}else if (isPrime[i+1]==1 && isPrime[i]==0 && flag2==0){
			r=i;
			flag2=1;
		}else if(i == n-1 && flag2 == 0 && isPrime[i]==0){
			r=i;
			flag2=1;
		}
		if(l!=-1 && r!=-1){
			int tem = l;
			while(cnt<=r-l+1){
				while(l<r){
					int temp = -1;
					for(int i=l;i<cnt;i++){
						if(flag3 == 0 && isPrime[i]==0 && isPrime[i+1]==0){
							temp = a[i]^a[i+1];
							flag3 = 1;
							continue;
						}
						if(isPrime[i]==0 && isPrime[i+1]==0) temp = temp^a[i+1];
					}
					if(temp == k){
						sum++;
						for(int i=l;i<cnt;i++){
							isPrime[i] = 1;
						}
					}
					l++;
				}
				cnt++;
				l = tem;
			}
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
			cnt = 2;
		}
	}
	cout<<sum;
	return 0;
}
//ฮาทþมห 
