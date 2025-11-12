#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;
int t,n; 
struct aaa{
	int a1,a2,a3,big,no,c1,c2,c3;
	}a[N];
void bigger(int x,int y,int z,int i){
		int root=0,ans=0;
		if(x>y)	{
			if(x>z){
				a[i].no=1;
				a[i].big=x;
			}else{
				a[i].no=3;
				a[i].big=z;
			}
		}else{
			if(y>=z){
				a[i].no=2;
				a[i].big=y;
			}else{
				a[i].no=3;
				a[i].big=z;
			}
		}
	}
bool cmp1(aaa x,aaa y){
//	cout<<"s ";
	return x.c1<y.c1;
}
bool cmp2(aaa x,aaa y){
	return x.c2<y.c2;
}
bool cmp3(aaa x,aaa y){
	return x.c3<y.c3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].c1=min(a[i].a1-a[i].a2,a[i].a1-a[i].a3);
			a[i].c2=min(a[i].a2-a[i].a1,a[i].a2-a[i].a3);
			a[i].c3=min(a[i].a3-a[i].a2,a[i].a3-a[i].a1);
			bigger(a[i].a1,a[i].a2,a[i].a3,i);	
		}
		int a1=0,a2=0,a3=0,ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i].big;
			switch(a[i].no){
				case 1:
					a1++;
					break;
				case 2:
					a2++;
					break;	
				case 3:
					a3++;
					break;		
			}
		//cout<<a1<<" "<<a[i].c1<<" "<<endl;
		}
		
		
		if(a1*2>n){
			sort(a,a+n,cmp1);
			for(int i=0;i<n;i++)
			//	cout<<i<<" "<<a[i].c1<<" "<<endl;
			for(int i=0;a1*2>n;i++,a1--){
				if(a[i].c1<=0){
					a1++;
					continue;
				}
				ans-=a[i].c1;
			}
		}
		if(a2*2>n){
			sort(a,a+n,cmp2);
			for(int i=0;a2*2>n;i++,a2--){
				if(a[i].c2<0){
					a2++;
					continue;
				}	
				ans-=a[i].c2;
			}
		}
		if(a3*2>n){
			sort(a,a+n,cmp3);
			for(int i=0;a3*2>n;i++,a3--){
				if(a[i].c3<=0){
					a3++;
					continue;
				}
				ans-=a[i].c3;
			//	cout<<i<<" "<<a[i].c3<<endl;			
			}
		}			
		cout<<ans<<endl;
	}
	return 0; 
} 
