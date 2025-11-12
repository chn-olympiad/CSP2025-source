#include<bits/stdc++.h>

using namespace std;

int inf=(1<<30)-1;
int cnt=0;

int n;
int a[100005];
int b[100005];
int c[100005];
int first[100005];
int a1=0,b1=0,c1=0;
int de[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(first,0,sizeof(first));
		memset(de,0,sizeof(de));
		a1=0,b1=0,c1=0,cnt=0;
		
		cin>>n;
		int half=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			cnt+=max(a[i],max(b[i],c[i]));
			if(a[i]>=b[i]&&a[i]>=c[i]){
				first[i]=1;
				a1++;
				de[i]=a[i]-max(b[i],c[i]);
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				first[i]=2;
				b1++;
				de[i]=b[i]-max(a[i],c[i]);
			}else{
				first[i]=3;
				c1++;
				de[i]=c[i]-max(a[i],b[i]);
			}
		}
		
		int k1=max(a1,max(b1,c1));
		if(k1>half){
			int num1=k1-half;
			int k;
			if(a1>=b1 && a1>=c1){
				k=1;
			}else if(b1>=a1&&b1>=c1){
				k=2;
			}else{
				k=3;
			}
			for(int i=0;i<n;i++){
				if(first[i]!=k){
					de[i]=inf;
				}
			}
			sort(de,de+n);
			for(int i=0;i<num1;i++){
				cnt-=de[i];
			}
		}
		cout<<cnt<<'\n';
		
	}
	
	return 0;
} 
