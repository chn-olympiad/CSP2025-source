int main(){
    string s1="xabcx", s2="xadex";
    int c=0;
    t1="xabcx", t2="xadex"
    for(int i=0;i<t1.length();i++){
        if(t1[i]==s1[i]){
            bool t=0;
            for(int j=0;j<s1.length();j++){
                if(t1[i+j]!=s1[j])
                    t=0;
            }
            if(t){
                for(int j=0;j<s1.length();j++){
                    t1[i+j]=s1[j];
                }
            }
        if(t1==t2) c++;
        }
    }
    cout<<c;
    return 0;
}
