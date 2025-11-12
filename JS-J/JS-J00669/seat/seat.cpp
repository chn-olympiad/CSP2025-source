
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int n,m;
int ma[100000];
int l[10000][10000];
int R;
int cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;

    for(int i=0;i<n*m;i++){
        cin>>ma[i];
    }
    R=ma[0];
    sort(ma,ma+m*n,cmp);
    int ii=0;

    for(int i=1;i<=m;++i){
        if(i%2==1){
            for(int j=1;j<=n;++j){
                l[j][i]=ma[ii];
                if(l[j][i]==R){
                    cout<<i<<" "<<j;
                }
                ii++;
            }
        }else{
		for(int j=n;j>=1;--j){
		l[j][i]=ma[ii];
                if(l[j][i]==R){
                    cout<<i<<" "<<j;
                }
                ii++;
            }

	}


    }
        fclose(stdin);
    fclose(stdout);
    return 0;
}

