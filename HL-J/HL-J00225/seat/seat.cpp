#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,g;
    cin>>n>>m;
    int ch = n*m;
    int a[ch] = {0};
    for(int i = 0;i<ch;i++){
            int temp;
            cin>>temp;
            a[i]=temp;
            if(i ==0){
                g = temp;
            }
        }
    sort(a,a+n*m,cmp);
    int x,y,z = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(a[z] ==g){
                x = i+1;
                if(i%2 == 0){
                    y = j+1;
                }
                else{
                    y = n-j;
                }
            }
            z++;
        }
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
