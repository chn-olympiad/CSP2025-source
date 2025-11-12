#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);
    int n;
    int r[10000];
    cin>>n;
    cin>>r[10000];
    if(n==1||n==2){
        cout << 0;
        }
        int max=0;
        int min=0;
        if(n==3){
            max = max(r[0],max(r[1],r[2]));
            min = min(r[0],min(r[1],r[2]));
	}
        if((r[0]+r[1])>max||(r[0]+r[2])>max||(r[2]+r[1])>max){
		    cout << 1;
	}

        if else(r[0]+r[1])<max||(r[0]+r[2])<max||(r[2]+r[1])<max){
            cout << 0;
        }
        fclose(stdin);
        fclose(stdout);
    return 0;
}

