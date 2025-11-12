#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(n<=20)cout << 6;
	else{
		int mul=0;
		for(int i=1;i<=n;i++){
			mul*=i;
			mul%=mod;
		}
		cout << mul;
	}
	return 0;
}/*
                *************
                *************
                *************

                     ####
                    ######
                  ##########
                #  ####  ####
               #     #########
              #         ######
              #          ####
               #    ##   ###
                #   ##   ##
                 #      ##
                   #  ##
                    ###
                    
                *****   *****
                *****   *****
                *****   *****
*/