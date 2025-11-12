#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int sco[121];
bool cmp(int s1,int s2){
    return s1>s2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,pos = 0,r;
    int ang=1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>sco[i];
    }
    r = sco[0];
    sort(sco,sco+n*m,cmp);
    for(int i=0;i<m;i++){
    	if(ang==1){
    		for(int j=0;j<n;j+=1){
	            a[j][i]=sco[pos];
	            pos++;;
        	}
		}else{
			for(int j=n-1;j>=0;j--){
	            a[j][i]=sco[pos];
	            pos++;
			}
    	}
        ang = ang*(-1);
    }
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j+=1){
            if(a[i][j] == r)cout<<i+1<<' '<<j+1;
//            cout<<a[i][j]<<' ';
        }
//        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
