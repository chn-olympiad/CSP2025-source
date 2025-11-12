#include<bits/stdc++.h>
using namespace std;
int my[1000001];
int lst[100001][4];
int n,myd=0,js=0;
bool cmp(int a,int b){
	return a>b;
}
int a=0,b=0,c=0;
void mine(int x){
	if(x>n)return;
	for(int i=1;i<=3;i++){
		if(i==1&&a<=n/2){
			
			mine(x+1);
			myd+=lst[x][i];
			my[js]+=myd;
			cout<<myd<<" ";
			js++;
			a++;
			myd=0;
		}
		if(i==2&&b<=n/2){
			
			mine(x+1);
			myd+=lst[x][i];
			my[js]+=myd;
			cout<<myd<<" ";
			js++;
			b++;  
			myd=0;                                           
		}
		if(i==3&&c<=n/2){
			
			mine(x+1);
			myd+=lst[x][i];
		cout<<myd<<" ";
			my[js]+=myd;
			js++;
			c++;
			myd=0;
		}
		else{
			js++;#include<bits/stdc++.h>
using namespace std;
int t,a=0;
int lst[4];
int myd=0;
void club(int n){
	for(int i=1;i<=n;i++){
		cin>>lst[1]>>lst[2]>>lst[3];
		a=lst[1];
		if(lst[2]>a)a=lst[2];
		if(lst[3]>a)a=lst[3];
		myd+=a;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)
	cin>>t;
	int num;
	for(int i=0;i<t;i++){
		cin>>num;
		club(num);
		cout<<myd<<endl;
		myd=0;
	}
	fclose(stdin);
	fclose(stdout);
} 
		}	
	}
	
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lst[i][1]>>lst[i][2]>>lst[i][3];
	}
	mine(1);
	sort(my,my+100000,cmp);
	cout<<my[1];
}
