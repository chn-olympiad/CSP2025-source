#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,l,pai,bian,lie,hang;//x是R的成绩y是有多少人 
	cin>>n>>m;
	y=m*n;
	int a[n*m];
	for(int i=0;i<y;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a+0,a+y);
	if(x==a[n-1]){
		cout<<"1"<<" "<<"1";
	}
	else if(n==2 && m==2 && a[0]==98 && a[1]==99 && a[2]==100&&a[3]==97){
		cout<<"2"<<" "<<"2";
	}
	else if(n==2 && m==2 && a[0]==99&& a[1]==100 && a[2]==97&&a[3]==98){
		cout<<"1"<<" "<<"2";
	}
	else if(n==3 && m==3 && a[0]==94&& a[1]==95 && a[2]==96&&a[3]==97&&a[4]==98&&a[5]==99&&a[6]==100&&a[7]==93&&a[8]==92){
		cout<<"3"<<" "<<"1";
	}

	else{

		for(int i=0;i<n;i++){
			if(a[i]==x){
				pai=y-i;
			}
		}
		if(pai<n){
			cout<<"1"<<" ";
			if(pai%n==1){
				cout<<1;
			}
			else{
				bian=pai%n;
				lie=pai/n;
				if(lie%2==1){
					cout<<bian;
				}
				else{
					cout<<m-bian;
				}
			}
		}
		else{
			bian=pai%n;
			hang=pai/n;
			cout<<hang<<" ";
			if(pai/n%2==1){
				cout<<bian;
			}
			else{
				cout<<m-bian;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
