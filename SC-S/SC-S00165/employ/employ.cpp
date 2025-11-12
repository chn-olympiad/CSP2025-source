 #include<bits/stdc++.h>
 using namespace std;
 int n,m,c[505];
 bool s[505],kf=0;
 int txr[505],klxr;
 int cap(int x,int y){
 	return x>y;
 }
 int lover=1;
 int main(){
 	freopen("empoly.in","r",stdin);
 	freopen("empoly.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>s[i];
 		if(s[i]==0){
 			for(int j=i;j<=n;j++){
 				txr[j]++;
			 }
		 }
	 }
 	for(int i=1;i<=n;i++){
 		cin>>c[i];
	 }
	sort(c+1,c+n+1,cap);
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;){
 			if(s[j]!=0&&c[j]>=txr[j]){
 				j++;
 				continue;
			 }
			 else{
			 	klxr=j;
			 	kf=1;
			 	break;
			 }
		 }
		 if(kf==1){
		 	break;
		 }
	 }
	 for(int i=klxr;i>=m;i--){
	 	lover*=i;
	 }
 	cout<<lover;
 	
 	
 	
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 } 