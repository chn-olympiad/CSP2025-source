#include<bits/stdc++.h>//±©Á¦ + Æ­Æ­»¨ 
 using namespace std;
int n,k,m,a[500005],sum;
bool vis[500005],flag;
int f(int x,int y){
	int num=a[x];
	for(int i=x+1;i<=y;i++)
		num^=a[i];
	return num;
}
void c(int x,int y){
	flag=1;
	for(int i=x;i<=y;i++){
		if(vis[i])
			flag=0;
	}	
}
 int main(){
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k<=1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k)sum++;
		}
		cout<<sum;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(f(i,j)==k){
					c(i,j);
					if(flag){
						sum++;
						for(int x=i;x<=j;x++)
							vis[x]=1;
					}
				}
			}
		}
		cout<<sum;
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
 
 
 
 //#include<bits/stdc++.h> 
// using namespace std;
//int n,k,m,a[500005],sum;
//bool vis[500005],flag;
//int f(int x,int y){
//	int num=a[x];
//	for(int i=x+1;i<=y;i++)
//		num^=a[i];
//	return num;
//}
// int main(){
// 	freopen("xor.in","r",stdin);
// 	freopen("xor.out","w",stdout);
//	cin>>n>>k;
//	for(int i=1;i<=n;i++)
//		cin>>a[i];
//	
//	for(int i=1;i<=n;i++){
//		int l=i,r=n;
//		while(l<r){
//			int mid=(l+r)/2;
//			if(f(l,r)>k)
//				r=mid;
//			else if(f(l,r)<k)
//				l=mid+1;
//			else if(f(l,r)==k){
//				for(int i=l;i<=r;i++){
//					if(vis[i])
//						flag=1;
//				}
//				if(flag){
//					flag=0;
//					break;
//				}
//				else{
//					sum++;
//					for(int i=l;i<=r;i++)
//						vis[i]=1;
//				}
//			}
//		}
//	}
//	cout<<sum;
// 	fclose(stdin);
// 	fclose(stdout);
// 	return 0;
// }


