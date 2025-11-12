#include<bits/stdc++.h>
using namespace std;


int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

	string s;
	long long num[10];
    long long n;

    for(int i=0;i<=9;i++){
        num[i]=0;
    }

	cin>>s;
	long long s_long = s.size();
	for(long long i = 0;i<s_long;i++){
        if((int)s[i]>=48 && (int)s[i]<=57){
            n=(long long)s[i] -48;
            num[n]++;

        }

	}




    for(int i = 9;i>=0;i--){
        if(num[i]!=0){
            for(long long j =0;j<num[i];j++){
                cout<<i;
            }


        }

	}
	return 0;
}
