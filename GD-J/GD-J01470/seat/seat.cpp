#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],R;
void go(int k,int x,int y,string s){
	//cout<<"k:"<<k<<" "<<y<<" "<<x<<" "<<s<<endl;
	if(k==0){
		cout<<y<<" "<<x;
		return;
	}
	if(s=="xia"){
		if(x+1<=n){
			go(k-1,x+1,y,"xia");
		}else if(x+1>n){
			go(k-1,x,y+1,"->");
		}
	}else if(s=="->"){
		if(x+1<=n)go(k-1,x+1,y,"xia");
		else if((x-1)>=1)go(k-1,x-1,y,"shang");
		else go(k-1,x,y+1,"->");
	}else if(s=="shang"){
		if(x-1>=1){
			go(k-1,x-1,y,"shang");
		}else if(x-1<1){
			go(k-1,x,y+1,"->");
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	int x=0;
	for(int i=2;i<=n*m;i++)
		if(a[i]>R)x++; 
	//cout<<x<<endl;
	go(x,1,1,"xia");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
