#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
struct node{
	bool isa;
	int sc;
}a[105];
bool cmp(node a,node b){
	return a.sc>b.sc;
}
bool flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[1].sc;
	a[1].isa=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].isa=0;
	}
	sort(a+1,a+(n*m)+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(flag)break;
		if(i%2!=0){
			for(int j=1;j<=n;j++,k++){
				if(a[k].isa){
					printf("%d %d",i,j);
					flag=1;
					k++;
					break;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--,k++){
				if(a[k].isa){
					printf("%d %d",i,j);
					flag=1;
					k++;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


