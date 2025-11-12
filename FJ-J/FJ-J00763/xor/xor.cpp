#include<bits/stdc++.h>//最后记得要删去注释 
using namespace std;
int n,k,a[500005],s;
bool b0,b1;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	cout<<n<<" ";
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cout<<1;
		if(i>0&&a[i]!=a[i-1]){
			b0=1;
			break;
		}
		if(i>1){
			b1=1;
			break;
		}
	}
	if(b0==0){
		cout<<n/2;
	}else if(b1==0&&b0==1){
		s=0;
		if(k==0){
			for(int i=0;i<n-1;i++){
				if(a[i]==a[i+1]){
					a[i]=a[i+1]=-1;
					s++;
				}
			}
		}else{
			for(int i=0;i<n-1;i++){
				cout<<a[i]<<" "<<a[i+1]<<'\n';
				if(a[i]!=a[i+1]&&a[i]>=0){
					a[i]=a[i+1]=-1;
					s++;
				}
			}
		}
		cout<<s;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
