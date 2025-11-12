#include<iostream>
#include<algorithm>
using namespace std;
int sco[1145];
bool cmp(int a,int b){
	return(a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>sco[i];
	int ming=sco[1],pla=0;
	sort(sco+1,sco+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sco[i]==ming){
			pla=i;
			break;
		}
	}
	int lie=0,han=0;
	if(pla%n)
		lie=pla/n+1,han=pla%n;
	else
		lie=pla/n,han=n;
	if(lie%2)
		cout<<lie<<" "<<han;
	else
		cout<<lie<<" "<<m-han+1;
	fclose(stdin);
	fclose(stdout);
}
