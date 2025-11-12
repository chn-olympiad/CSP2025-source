#include<bits/stdc++.h>
using namespace std;
int stu[105];
int now;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>stu[i];
	}
	int a=stu[0];
	sort(stu,stu+n*m);
	now=n*m-1;
	bool up=0;
	for(int i=0;i<m;i++){
		if(up){
			for(int j=n-1;j>=0;j--){
				if(stu[now]==a){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				else now--;
			}
			up=0;
		}
		else{
			for(int j=0;j<n;j++){
				if(stu[now]==a){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				else now--;
			}
			up=1;
		}
	}
	return 0;
}
