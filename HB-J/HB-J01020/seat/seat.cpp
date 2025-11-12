#include<bits/stdc++.h>
using namespace std;
int x,y;
int xx,yx;
int a[110];
bool amp(int s1,int s2){
    return s1>s2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>x>>y;
    xx = 1;yx = 1;
    int k = x*y;
    for (int i = 1; i <= k; i++)
    {
        cin>>a[i];
    }
    int g = a[1];
    sort(a+1,a+k+1,amp);
    for (int i = 1; i <= k; i++)
    {	
		if(a[i]==g){
			cout<<xx<<" "<<yx<<"\n";
		}
        if(xx%2==0){
            if(yx==1){
                xx = xx+1;
            }
            else{
                yx = yx-1;
            }
        }
        else{
            if(yx==y){
                xx = xx+1;
            }
            else{
                yx = yx+1;
            }
        }
        
    }
    
    return 0;
}
