#include<bits/stdc++.h>
using namespace std;
int t=0;
int n=0,ans=0;
int shuju[100001];
int a1,b1,c1;
struct node{
	int place,num;
};
bool comp(node l,node r){
 	return l.num<r.num;
}
node op[100001]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,c;
	cin>>t;
	int der;
	while(t--){
		ans=0;a1=0;b1=0;c1=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		if(a==b && a>c){
			a1++;
			shuju[i]=a;
			op[i].place=1;
			op[i].num=min(a-b,a-c);
		}
		else if(b==c && c>b){
			b1++;
			shuju[i]=b;
			op[i].place=2;
			op[i].num=min(b-c,b-a);
		}
		else if(a==c && a>b){
			a1++;
			shuju[i]=a;
			op[i].place=1;
			op[i].num=min(a-b,a-c);
		}
		else if(a>b && a>c) {
			a1++;
			shuju[i]=a;
			op[i].place=1;
			op[i].num=min(a-b,a-c);
			}
		else if(b>a && b>c){
			b1++;
			shuju[i]=b;
			op[i].place=2;
			op[i].num=min(b-a,b-c);
			}
		else /*if(c>a && c>b)*/{
			c1++;
			shuju[i]=c;
			op[i].place=3;
			op[i].num=min(c-b,c-a);
			} 
		}
		for(int i=1;i<=n;i++){
			if(op[i].num==-6812) cout<<i;
		}
		sort(op+1,op+n+1,comp); 
	/*	for(int i=1;i<=n;i++){
			cout<<op[i].num<<" ";
		}*/ 
		//cout<<endl<<"!"<<" "<<a1<<" "<<b1<<" "<<c1<<endl;
		//*
		
		for(int i=1;i<=n;i++){
			ans+=shuju[i];
		}
		//*/
		if(a1>n/2){
		der=a1-n/2;
		for(int i=1;i<=n;i++){
			if(op[i].place==1 && der!=0){
				der--;
				ans-=op[i].num;
				}
			}		
		}
		
		else if(b1>n/2){
		//cout<<b1<<endl;
		der=b1-n/2;
		for(int i=1;i<=n;i++){
			if(op[i].place==2 && der!=0){
				der--;
				ans-=op[i].num;
				}
			}		
		}
		
		else if(c1>n/2){
		//cout<<c1<<endl;
		der=c1-n/2;
		for(int i=1;i<=n;i++){
			if(op[i].place==3 && der!=0){
				der--;
				ans-=op[i].num;
				}
			}		
		}
		/*for(int i=1;i<=n;i++){
			cout<<op[i].num<<endl;
		}*/
		cout<<ans<<endl;
	}
	return 0; 
}/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0


*/
