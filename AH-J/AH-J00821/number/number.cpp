#include<bits/stdc++.h>
using namespace std;
int give(char str[],int cnt1){
    char s1[]="";
    int cnt=0;

    cout<<1;
    for ( int i=0;i<cnt1;i++){
        if(str[i]>='0'&&str[i]<='9'){
            s1[cnt++]=str[i];
        }
    }
    char s2[]="";
    for (int i=cnt-1;i>=0;i++){
        s2[cnt-i]=s1[i];
    }
    int n;
    sscanf(s2,"%d",&n);
    return n;
}
int main(){
	char s[100005];
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    int cnt=0;
    for(int i=0;;i++){
		if(s[i]=='\0'){
			cnt=i;
			break;
		}
	}
    int t=give(s,cnt);
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


