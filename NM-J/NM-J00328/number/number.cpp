#include<iostream>
#include<cstring>

using namespace std;

string s;

int k[10]={0,0,0,0,0,0,0,0,0,0};

bool b=false;

int to_num(){
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int x=s[i]-'0';
            k[x]+=1;
            if(x!=0)b=true;
        }
    }
    return 0;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    to_num();
    if(b){
        for(int i=9;i>=0;i--){
            for(int j=0;j<k[i];j++){
                printf("%d",i);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
