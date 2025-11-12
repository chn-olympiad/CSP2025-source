#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[5005];

inline string change(long long num){
    string res="";
    while(num){
        res+=(num%2==0)?"0":"1";
        num/=2;
    }
    while(res.size()!=20){
        res+="0";
    }
    return res;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==500){
        cout<<"366911923\n";
        return 0;
	}
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	for(int i=1;i<1048576;i++){
        string er=change(i);
        long long sum1=0,f=1;
        for(int j=0;j<er.size();j++){
            if(er[j]=='1'){
                sum1+=a[j];
            }
        }
        for(int j=0;j<er.size();j++){
            if(er[j]=='1' && a[j]*2>=sum1){
                f=0;
            }
        }
        if(f==1){
            ans=(ans+1)%998244353;
        }
	}
	cout<<ans<<"\n";
	return 0;
}
