#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int op=0;
struct node{
    int v,id;
}x[105];
bool cmp(node x,node y){
    return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>x[i].v;
        x[i].id=i;
	}
	sort(x+1,x+(n*m)+1,cmp);
	a=1,b=1;
	for(int i=1;i<=n*m;i++){
        if(x[i].id==1){
            break;
        }
        if(op==0){
            if(b==n){
                op=1;a=a+1;
            }else{
                b=b+1;
            }
        }else{
            if(b==1){
                op=0;a=a+1;
            }else{
                b=b-1;
            }
        }
	}
	cout<<a<<" "<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

