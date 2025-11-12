#include<bits/stdc++.h>
using namespace std;
string a;
int b[110],d,x,y,cnt,x1=0,y2;
bool tem;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=0;i<=x*y-1;i++){
        cin>>b[i];
	}
	d=b[0];
	sort(b,b+x*y);
	for(int i=x*y;i>=0;i--){
    	if(b[i]==d){
            break;
        }else{
            cnt++;
        }
	}
	cout<<cnt/y+1;
	if(cnt/y%2==0){
		cout<<" "<<cnt%x+1;
	}else{
		cout<<" "<<x-cnt%x+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
