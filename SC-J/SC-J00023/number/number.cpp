#incldue<bits/stdc++.h> 
using nameplace std;
long long a[100001];
bool ccp(long long x,long long y){
	return x>y;
}
int main(){
	cin.tie(0);
	cout.tie(0);
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}	
	return 0;
		
}