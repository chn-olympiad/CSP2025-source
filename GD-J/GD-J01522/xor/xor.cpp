#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
ll n,k;
ll a[N];
bool flag1=1;
bool flag01=1;
int pos,j=1;
ll s[N];
ll ans,maxn;
int main(){
//	int a;
//	a=1^1^1;
//	cout<<a;

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=0;
		if(a[i]>=2)flag01=0;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	
//	cout<<flag1<<" "<<flag01;
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
	//cout<<endl;
//	int a =s[2]^s[0];
//	cout<< a <<endl;
	if(k==0&&flag1){
		cout<<n<<endl;
		return 0;
	}
	else if (k==1&&flag01){
		ans = 0;
		//cout<<"!";
		for(int i=1;i<=n;i++){
			pos = a[i];
			j=i+1;
			while(a[j]!=pos&&j<=n)j++;
			j--;
			ans++;
			//cout<< "i:"<<i << " "<<"j:"<<j <<endl;
			i = j;
		}
		cout<<ans;
		return 0;
	}
	else{
		ans = 0;
		for(int len = 1;len<=n;len++){
			ans = 0;
			for(int i=len;i<=n;i++){
				
				j = i;
				while(int(s[j]^s[i-1])!=k&&j<=n)j++;
				if(j==n+1)continue;
				ans++;
				//cout<< "i:"<<i << " "<<"j:"<<j <<endl;
				i=j;
			}
			maxn = max(maxn,ans);
			//cout<<"maxn:"<<maxn<<endl;
			
		}
		cout<<maxn;
	}
	return 0;
}

