#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,r;
	cin>>n>>m;
	s=n*m;
	int seat[15][15],stu[110],stud[110];
	for(int i=1;i<=s;i++) cin>>stu[i];
	r=stu[1];
	sort(stu,stu+s+1);
	for(int i=s;i>=0;i--){
		stud[i]=stu[s-i+1];
	}
	s=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(r==stud[s]){
					cout<<i<<" "<<j;
					return 0; 
				}
				s++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(r==stud[s]){
					cout<<i<<" "<<j;
					return 0; 
				}
				s++;
			}
		}
	}
	return 0;
}
