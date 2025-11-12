#include<bits/stdc++.h>
using namespace std;
int n,m;
	struct student{
		int grade,bh;
		};
		student a[105];
bool jiangxu(student a,student b){
	return a.grade>b.grade;
	}
int main(){
freopen(".in","r",stdin);
freopen(".out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	a[i].bh=i;
	cin>>a[i].grade;
	}
	sort(a+1,a+n*m+1,jiangxu);
int uh;
for(int i=1;i<=n*m;i++){
	if(a[i].bh==1){
		uh=i;
		break;
		}
	}
	cout<<(uh-1)/n+1<<' '<<(((uh-1)/n+1)%2==1 ? ((uh-1)%n+1) : n-((uh-1)%n));
fclose(stdin);
fclose(stdout);                                                     
}
