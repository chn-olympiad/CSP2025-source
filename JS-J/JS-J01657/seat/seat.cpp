#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,yy;
float y;
struct node{
    int a;
    int v;
};
bool cmp(node x,node y){
    return x.v>y.v;
}
vector<node> num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	scanf("%d%d",&n,&m);
	num.resize(n*m+1);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&num[i].v);
        num[i].a=i;
    }
    sort(num.begin()+1,num.end(),cmp);
    for(int i=1;i<n*m;i++){
        if(num[i].a==1){
            yy=ceil(i*1.0/n);
            if(yy%2==1){
                x=i-(yy-1)*n;
            }
            else if(yy%2==0){
                x=(n+1-(i-(yy-1)*n));
            }
            break;
        }
    }
    cout<<yy<<' '<<x;
	return 0;
}
