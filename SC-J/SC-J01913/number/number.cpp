 #include<bits/stdc++.h>
 using namespace std;
 bool cop(int a,int b){
 	  return a>b;
 }
string a;
int cnt[1000006];
 int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	cin>>a;
 	int n=a.size();
 	int s=0;
 	for(int i=0;i<n;i++){
 		if(a[i]>='0'&&a[i]<='9'){
 			cnt[i]=a[i]-48;
 			s++;
		 }
	 }
	 sort(cnt,cnt+n,cop);
	 for(int i=0;i<s;i++){
	 	cout<<cnt[i];
	 }
	 fclose(stdin);
	 fclose(stdout);
 	return 0;
 }