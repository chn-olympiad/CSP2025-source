#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,a[100005],cnt=0,sum=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	for(long long i=1;i<=n;i++){
		if(s[i-1]=='0'){
			sum++;
		}
		else if(sum>=a[i]){
			sum++;
		}
		if(sum>=n){
			break;
		}
	}
	if(n-sum<m){
		cnt=0;
	}
	if(n-sum>=m){
		cnt++;
//		cout<<" 1"<<endl;
	}

	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			sum=0;
//			cout<<a[i]<<" "<<a[j]<<" 1"<<endl;
			swap(a[i],a[j]);
//			cout<<a[i]<<" "<<a[j]<<" 2"<<endl;
			for(long long k=1;k<=n;k++){
				if(s[k-1]=='0'){//如果这道题太难，直接走 
					sum++;
//					cout<<k<<" "<<sum<<" 1"<<endl;
				}
				else if(sum>=a[k]){//如果走的人超过忍耐上限，走 
					sum++;
//					cout<<k<<" "<<sum<<" 2"<<endl;
				}
				if(n-sum<m){//如果走的人比他要求的人多，结束 
					break;
				}
			}
//			swap(a[i],a[j]);
//			cout<<a[i]<<" "<<a[j]<<" 3"<<endl;
			if(n-sum>=m){
				cnt++;
//				cout<<sum<<" "<<i<<" "<<j<<" 4"<<endl;
			}
		}
	
	}
	cout<<cnt;
	return 0;
}
