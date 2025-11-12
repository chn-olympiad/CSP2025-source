//GZ-S00156 黄平县谷陇中学 张应祥 
#include<bits/stdc++.h>
using namespace std;
int n,t;
int j=3;
int a[4][200];
int q[4];
int main(){
    freopen(club.in,'r',in);
    freopen(club.out,'w',out); 

    cin>>t;
    cin>>n;
    for (int i=0;i<t;i++){
        for(int k=0;k<n;k++){
            int b=3;
            for(int b=0;b<j;b++){
                cin>>a[k][b];
            }
            if(a[k][b]>a[k][b-1]>a[k][b-2]){
                q[k]=q[k]+a[k][b];
            }else if(a[k][b]<a[k][b-1]<a[k][b-2]){
                q[k]=q[k]+a[k][b-2];
            }else{
                q[k]=q[k]+a[k][b-1];
            }
        }
    }
    for (int i=0;i<n;i++){
    	cout<<q[i]<<endl;
	}
    return 0;
}
