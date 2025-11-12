 #include<bits/stdc++.h>
 using namespace std;
 int a[1000]={};
 int ind=0;
 bool cmp(int x,int y){
	 return x>y;
 }
 int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string in;
	cin>>in;
	for(long unsigned int i=0;i<in.size();i++){
		if(in[i]>='0'&&in[i]<='9'){
			a[ind++]=(int)(in[i]-'0');
		}
	}
	sort(a,a+ind,cmp);
	for(int i=0;i<ind;i++){
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
 
