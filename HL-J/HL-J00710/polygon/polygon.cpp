#include<bits/stdc++.h>
using namespace std;
long long T(int n){
	long long ans = 1;
	for(int i = 1;i<=n;i++){
		ans *= i;
	}
	return ans;
}
long long C(int a,int b){
	long long c= T(b) / (T(a)*T(b-a));
	return c;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> S(n);
    for(int i = 0;i<n;i++){
        cin>>S[i];
    }
    long long ans = 0;
    sort(S.begin(),S.end());
    for(int i = 2;i<n;i++){
		int p = i-2;
		long long temp = S[i-1];
		while(temp<S[i] && p>=0){
			temp+=S[p];
			p--;
		}
		if(temp>S[i]){
			p++;
			for(int j = 1;j<=p;j++){
				ans += C(j,p);
			}
		}
	}
    cout<<ans*2 % 998244353<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
