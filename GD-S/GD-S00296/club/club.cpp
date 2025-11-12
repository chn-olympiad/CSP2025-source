#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int u=0;u<T;u++){
		int n,num=0,arr[1000000]={},brr[1000000]={},crr[1000000]={};
		int ar=0,br=0,cr=0,q=-1,w=-1,e=-1;
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				num+=a;
				q++;
				arr[q]=a-max(b,c);
				int r=q-1;
				while(arr[r]<arr[r+1]&&r>=0){
					swap(arr[r],arr[r+1]);
					r--;
				}
				if(ar+1>n/2){
					num-=arr[q];
					q--;
				}else ar++;
			}else if(b>=a&&b>=c){
				num+=b;
				w++;
				brr[w]=b-max(a,c);
				int r=w-1;
				while(brr[r]<brr[r+1]&&r>=0){
					swap(brr[r],brr[r+1]);
					r--;
				}
				if(br+1>n/2){
					num-=brr[w];
					w--;
				}else br++;
			}else if(c>=a&&c>=b){
				num+=c;
				e++;
				crr[e]=c-max(a,b);
				int r=e-1;
				while(crr[r]<crr[r+1]&&r>=0){
					swap(crr[r],crr[r+1]);
					r--;
				}
				if(cr+1>n/2){
					num-=crr[e];
					e--;
				}else cr++;
			}
			
		}
		cout<<num<<endl;
	}
	return 0;
} 
