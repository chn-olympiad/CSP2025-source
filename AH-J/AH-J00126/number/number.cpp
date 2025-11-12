#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
string s;
priority_queue<int> st;
int main(){
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                int h=s[i]-'0';
                st.push(h);
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        //fclose(stdin);
        //fclose(stdout);
        return 0;
}
