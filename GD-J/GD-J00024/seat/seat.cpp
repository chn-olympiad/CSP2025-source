#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,p,ds=0;
    int l[105][105]={},d[100005];
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>d[i];

    }t=d[0];
    sort(d,d+n*m,cmp);
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(i%2==0){
    			l[i][j]=d[ds];
    			ds++;
			}else if(i%2!=0){

				l[i][m-j-1]=d[ds];
				ds++;
			}
		}
	}
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(l[i][j]==t){
    			cout<<i+1<<" "<<j+1;
    			break;
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

