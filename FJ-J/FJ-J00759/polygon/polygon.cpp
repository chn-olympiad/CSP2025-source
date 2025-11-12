 #include<bits/stdc++.h>
 using namespace std;
 const long long Mod= 998244353;
 int a[5005],n,ans,num,bs[5005];
 bool bj[5005];
 vector<int>p;
 void inint(){
 	bs[1]=1;
 	for(int i=2;i<=n;i++){
 		bs[i]=bs[i-1]*i;
	 }
	 return;
 }
 void dfs(int x){
 	if(p.size()==x){
 		int zd=0,he=0;
 		for(int i=0;i<p.size();i++){
 			he+=p[i];
 			zd=max(zd,p[i]);
		 }
		 if(he>zd*2){
		 	num++;
		 	//
//		 	for(int i=0;i<p.size();i++){
//		 		cout<<p[i]<<" ";
//			 }cout<<"\n";
		 }
//		 return;
	 }
	 for(int i=1;i<=n;i++){
	 	if(bj[i]==0){
	 		bj[i]=1;
	 		p.push_back(a[i]);
	 		dfs(x);
	 		bj[i]=0;
	 		p.pop_back();
		 }
	 }
 }
 int main(){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	int zh=0;
 	cin>>n;
 	inint();
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		zh+=a[i];
	 }
	 sort(a+1,a+1+n);
	 if(zh>a[n]*2){
	 	num+=1;
	 }
	 for(int i=3;i<=n;i++){
	 	dfs(i);
	 	num=num/bs[i];
	 	
	 	ans+=num;
	 	num=0;
	 }
	 cout<<ans;
 	return 0;
 }
