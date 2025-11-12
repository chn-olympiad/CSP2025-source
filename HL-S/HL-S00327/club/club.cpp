#include<bits/stdc++.h>
using namespace std;
int n[100005][4];
int main(){
    int a=3;
    int h=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,j;//t ren,j zu
	scanf("%d",&t);

	for(int k=0,k<=t,k++){
            scanf("%d",&j);
        for(int i=0,i<=j,i++){
                for(int d=0,d<=a,d++){
                    cin>>n[i+1][d];

                }
     h+=max(n[i][1],n[i][a]);

}printf("%d",h);
}

	return 0;
}
