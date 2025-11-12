#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100005][4][6],z,t;
int b[4];
long long sum;
long long cnt;
void s(int n){
	if(n==1){
		for(int i=1;i<=3;i++){
			if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
				cnt=max(cnt,sum);
			}
		}
	}
	for(int i=1;i<=3;i++){
		s(n--);
		b[i]++;
		sum+=a[n][i][z];
	}
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(z=1;z<=t;z++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1][z]>>a[i][2][z]>>a[i][3][z];
        }
        s(n);
		cout<<cnt<<endl;
    }

    return 0;
}
