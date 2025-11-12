#include<bits/stdc++.h>
using namespace std;
struct student{
    int id,score;
}a[101];
bool cmp(student a,student b){
	return a.score>b.score;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}	
    sort(a+1,a+n*m+1,cmp);
    int ans;
    for(ans=1;ans<=n*m;ans++)if(a[ans].id==1)break;
    int f=0;
    int i,j,k;
    for(i=1,j=1,k=1;k<ans;k++){
		if(f==0){
			if(i==n){
				j++;
				f=1;
			}
			else{
				i++;
			}
		}
		else {
			if(i==1){
				j++;
				f=0;
			}
			else {
				i--;
			}
		}
	}
	cout<<j<<" "<<i<<endl;
    return 0;
}
