 #include<iostream>
 using namespace std;
 int main(){
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	int n,w,ans=0,cnt=0,p;
 	int s[500005]={};
 	cin>>n;
 	cin>>w;
 	for(int i=1;i<=n;i++){
 		cin>>p;
 		s[i]=s[i-1]^p;
	}
	for(int i=1;i<=n;i++){
	 	for(int j=cnt;j<i;j++){
	 		int x=s[i],y=s[j];
	 		int z=(int)x^y;
	 		if((z==w)){
	 			ans++;
	 			cnt=i;
	 			break;
			}
		}
	}
	cout<<ans;
	return 0;
 }